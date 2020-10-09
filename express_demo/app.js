const express = require("express");
const bodyParser = require("body-parser");
const cookieParser = require("cookie-parser");
const session = require("express-session");
const MongoStore = require("connect-mongo")(session);
const app = express();
const login = require("./routes/login");
const register = require("./routes/register");
const admin = require("./routes/admin");
const main = require("./routes/main");
const upload = require("./routes/upload");

//配置cookie-parser中间件
app.use(cookieParser());
//配置session中间件
app.use(
  session({
    secret: "this is session", // 服务端生成session签名
    resave: false, // 强制存储session即使它没有发生变化
    saveUninitialized: true, //强制将未初始化的session存储
    cookie: {
      //session是基于cookie
      secure: false, //true代表只有https协议才能访问cookie
      maxAge: 1000 * 60 * 30, //设置session的过期时间
    },
    store: new MongoStore({
      url: "mongodb://trafal:991220@localhost:27017/trafal",
    }),
  })
);
//配置第三方中间件
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
//配置模板引擎，只需要安装，不需要引入即可使用
app.set("view engine", "ejs");
//配置静态web目录 （在获得路径时先查看所设置的静态目录有没有所需要的文件，如果没有才向下继续查询）
app.use(express.static("static"));

//挂载模块
app.use("/", main);
app.use("/login", login);
app.use("/register", register);
app.use("/admin", admin);
app.use("/upload", upload);

//错误处理中间件 (要放在最后)
app.use((req, res, next) => {
  res.status(404).send("404");
});
app.listen(8081);
