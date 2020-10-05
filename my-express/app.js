const http = require("http");
const app = require("./module/router");
const ejs = require("ejs");
const { MongoClient } = require("mongodb");
const queryString = require("querystring");

//定义数据库连接的地址
const url = "mongodb://trafal:991220@127.0.0.1:27017/trafal";
//定义要操作的数据库
const dbName = "trafal";
//实例化MongoClient 传入数据库链接地址
// const client = new MongoClient(url, { useUnifiedTopology: true });

//注册web服务
http.createServer(app).listen(8081);

//app.static("public"); //修改静态web目录

/*
 *
 *
 *
 *
 *
 */

//配置路由
app.get("/", function (req, res) {
  MongoClient.connect(url, { useUnifiedTopology: true }, (err, client) => {
    if (err) {
      console.log(err);
      return;
    }
    let db = client.db(dbName);

    //查询数据
    db.collection("user")
      .find({})
      .toArray((err, result) => {
        if (err) {
          console.log(err);
          return;
        }
        client.close();
        ejs.renderFile("./views/index.ejs", { list: result }, (err, data) => {
          res.send(data);
        });
      });
  });
});

app.get("/register", function (req, res) {
  ejs.renderFile("./views/register.ejs", {}, (err, data) => {
    res.send(data);
  });
});

app.get("/login", function (req, res) {
  //   res.writeHead(200, { "Content-Type": "text/html;charset='utf-8'" });
  //   res.end("login");
  ejs.renderFile("./views/form.ejs", {}, (err, data) => {
    res.send(data);
  });
});
app.get("/news", function (req, res) {
  res.send("news");
});
app.post("/doRegister", function (req, res) {
  //解析post
  let body = queryString.parse(req.body);
  //传送到数据库
  MongoClient.connect(url, { useUnifiedTopology: true }, (err, client) => {
    if (err) {
      console.log(err);
      return;
    }
    let db = client.db(dbName);
    db.collection("user").insertOne(body, (err, result) => {
      if (err) {
        console.log(err);
        return;
      }
      console.log("增加数据成功");
      res.send("增加数据成功");
    });
  });
});
