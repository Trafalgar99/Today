const fs = require("fs");
const path = require("path");
const url = require("url");
const ejs = require("ejs");

let getFileMime = function (extname) {
  let data = fs.readFileSync("./data/mime.json");
  // console.log(typeof data);
  let mimeObj = JSON.parse(data.toString());
  return mimeObj[extname.slice(1)];
};
// exports.getFileMime = getFileMime;

let app = {
  static: (req, res, staticPath) => {
    //获取地址
    let pathname = url.parse(req.url).pathname;
    pathname = pathname == "/" ? "/index.html" : pathname;
    let extname = path.extname(pathname);
    //通过fs模块读取文件
    if (pathname != "/favicon.ico") {
      try {
        let data = fs.readFileSync("./" + staticPath + pathname);

        if (data) {
          let mime = getFileMime(extname);
          // console.log(mime);
          res.writeHead(200, {
            "Content-Type": "" + mime + ';charset="utf-8"',
          });
          res.end(data);
        }
      } catch (err) {
        // console.error(err);
      }
    }
  },
  login: (req, res) => {
    //获取地址
    let pathname = url.parse(req.url).pathname;
    pathname = pathname == "/" ? "/index.html" : pathname;
    let extname = path.extname(pathname);
    let msg = "aaaaaaaaaaa";
    ejs.renderFile("./view/login.ejs", { msg: msg }, (err, data) => {
      console.log(err);
      res.writeHead(
        200,
        `Content-Type:${getFileMime(extname)};charset:'utf-8'`
      );

      res.end(data);
    });
  },
  news: (req, res) => {
    res.end("news");
  },
  register: (req, res) => {
    res.end("register");
  },
  error: (req, res) => {
    res.end("error");
  },
};

module.exports = app;
