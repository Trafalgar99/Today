const http = require("http");
const routes = require("./module/routes");
const url = require("url");

http
  .createServer((req, res) => {
    //创建静态web服务
    routes.static(req, res, "code");

    //路由
    let pathname = url.parse(req.url).pathname.replace("/", "");

    //
    try {
      routes[pathname](req, res);
    } catch (e) {
      routes["error"](req, res);
    }
  })
  .listen(8081);

// console.log("http://127.0.0.1:8081/login.html");
