const url = require("url");
const fs = require("fs");
const path = require("path");

//扩展res
function changeRes(res) {
  res.send = (data) => {
    res.writeHead(200, { "Content-Type": "text/html;charset='utf-8'" });
    res.end(data);
  };
}
//根据后缀名获取文件类型
function getFileMime(extname) {
  let data = fs.readFileSync("./data/mime.json");
  let mimeObj = JSON.parse(data.toString());
  return mimeObj[extname.slice(1)];
}
//静态web服务方法
function initStatic(req, res, staticPath) {
  //获取地址
  let pathname = url.parse(req.url).pathname;
  pathname = pathname == "/" ? "index/html" : pathname;
  let extname = path.extname(pathname);
  //通过fs模块读取文件
  if (pathname != "favicon.ico") {
    try {
      let data = fs.readFileSync("./" + staticPath + pathname);
      if (data) {
        let mime = getFileMime(extname);
        res.writeHead(200, { "Content-Type": `${mime};charset='utf-8'` });
        res.end(data);
      }
    } catch (e) {}
  }
}

let server = () => {
  let G = {
    //把get和post分开
    _get: {},
    _post: {},
    staticPath: "static", //默认静态web目录
  };

  let app = function (req, res) {
    //扩展res的方法
    changeRes(res);
    //配置静态web服务
    initStatic(req, res, G.staticPath);

    let pathname = url.parse(req.url).pathname;
    //获取请求类型
    let method = req.method.toLowerCase();

    if (G["_" + method][pathname]) {
      if (method == "get") {
        G._get[pathname](req, res);
      } else {
        //获取post的数据
        let postData = "";
        req.on("data", (chunk) => {
          postData += chunk;
        });
        req.on("end", () => {
          req.body = postData;
          G._post[pathname](req, res);
        });
      }
    } else {
      res.writeHead(404, { "Content-Type": "text/html;charset='utf-8'" });
      res.end("not exist");
    }
  };

  //配置get/post请求
  app.get = function (str, callback) {
    //注册方法
    G._get[str] = callback;
  };
  app.post = function (str, callback) {
    G._post[str] = callback;
  };
  //配置静态web服务目录
  app.static = function (staticPath) {
    G.staticPath = staticPath;
  };

  return app;
};

module.exports = server();
