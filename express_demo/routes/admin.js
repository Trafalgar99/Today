const express = require("express");

let router = express.Router();

router.get("/", (req, res) => {
  //获取session
  if (req.session.username) res.send(req.session.username + "okokokok");
  else {
    res.send("fail");
  }
});
router.get("/article", (req, res) => {
  //获取设定好的cookie
  let username = req.cookies.username;
  console.log(username);
  res.send("新闻页面");
});
//动态路由
router.get("/article/:id", (req, res) => {
  let id = req.params; //动态路由的参数（id）
  console.log(id);
  res.send("动态路由");
});

//获取get传值
router.get("/product", (req, res) => {
  query = req.query;
  console.log(query);
  res.send("product");
});

module.exports = router;
