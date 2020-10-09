const express = require("express");

let router = express.Router();

router.get("/", (req, res) => {
  //在首页里设置cookie
  res.cookie("username", "Trafal", { maxAge: 1000 * 60 * 60 });
  let title = "abc";
  res.render("index", { title: title }); //会默认到views寻找
});

module.exports = router;
