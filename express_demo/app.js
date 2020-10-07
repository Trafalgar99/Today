const express = require("express");
const bodyParser = require("body-parser");
const cookieParser = require("cookie-parser");
const app = express();

//配置cookie-parser中间件
app.use(cookieParser());

//应用级中间件（用于权限判断）
app.use((req, res, next) => {
  // console.log(new Date());
  next(); //继续向下匹配
});
//配置第三方中间件
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.set("view engine", "ejs"); //配置模板引擎，只需要安装，不需要引入即可使用
//配置静态web目录 （在获得路径时先查看所设置的静态目录有没有所需要的文件，如果没有才向下继续查询）
app.use(express.static("static"));

app.get("/", (req, res) => {
  //在首页里设置cookie
  res.cookie("username", "Trafal", { maxAge: 1000 * 60 * 60 });
  let title = "abc";
  res.render("index", { title: title }); //会默认到views寻找
});
app.get("/article", (req, res) => {
  //获取设定好的cookie
  let username = req.cookies.username;
  console.log(username);
  res.send("新闻页面");
});
app.get("/register", (req, res) => {
  res.send("注册");
});
app.get("/login", (req, res) => {
  res.render("login", {}, function (err, data) {
    if (err) console.log(err);
    res.send(data);
  });
});
app.post("/doLogin", (req, res) => {
  res.render("doLogin", {}, function (err, data) {
    res.send(data);
  });
  console.log(req.body);
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

//获取get传值
app.get("/product", (req, res) => {
  query = req.query;
  console.log(query);
  res.send("product");
});
//错误处理中间件 (要放在最后)
app.use((req, res, next) => {
  res.status(404).send("404");
});
app.listen(8081);
