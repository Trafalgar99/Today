const express = require("express");

const app = express();

app.set("view engine", "ejs"); //配置模板引擎，只需要安装，不需要引入即可使用
//配置静态web目录
app.use(express.static("static"));

app.get("/", (req, res) => {
  let title = "abc";
  res.render("index", { title: title }); //会默认到views寻找
});
app.get("/article", (req, res) => {
  res.send("新闻页面");
});
app.get("/register", (req, res) => {
  res.send("注册");
});
app.get("/login", (req, res) => {
  res.send("登录");
});
app.post("/doLogin", (req, res) => {
  res.send("执行登录");
});
app.put("/put", (req, res) => {
  console.log("修改");
  res.send("修改");
});
app.delete("/delete", (req, res) => {
  console.log("删除");
  res.send("删除");
});

app.get("/admin/user", (req, res) => {
  res.send("admin user");
});
//动态路由
app.get("/article/:id", (req, res) => {
  let id = req.params; //动态路由的参数（id）
  console.log(id);
  res.send("动态路由");
});
//get传值
app.get("/product", (req, res) => {
  query = req.query;
  console.log(query);
  res.send("product");
});

app.listen(8081);
