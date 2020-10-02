const http = require("http");
const app = require("./module/router");
const ejs = require("ejs");

//注册web服务
http.createServer(app).listen(8081);

//app.static("public"); //修改静态web目录

//配置路由
app.get("/login", function (req, res) {
  //   res.writeHead(200, { "Content-Type": "text/html;charset='utf-8'" });
  //   res.end("login");
  ejs.renderFile("./views/form.ejs", {}, (err, data) => {
    res.send(data);
  });
});
app.get("/", function (req, res) {
  res.send("首页");
});
app.get("/news", function (req, res) {
  res.send("news");
});
