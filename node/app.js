const http = require("http");
const routes = require("./module/routes");
const url = require("url");
http
  .createServer((req, res) => {
    //创建静态web服务
    routes.static(req, res, "code");

    //路由

    let pathname = url.parse(req.url).pathname;
    // console.log(pathname);
    if (pathname == "/login") {
      res.writeHead(200, { "Content-type": "text/html;charset='utf-8'" });
      res.end("login");
    } else if (pathname == "/register") {
      res.writeHead(200, { "Content-type": "text/html;charset='utf-8'" });
      res.end("register");
    } else if (pathname == "/admin") {
      res.writeHead(200, { "Content-type": "text/html;charset='utf-8'" });
      res.end("admin");
    } else {
      res.writeHead(404, { "Content-type": "text/html;charset='utf-8'" });
      res.end("not exist");
    }
  })
  .listen(8081);

console.log("http://127.0.0.1:8081/login.html");
