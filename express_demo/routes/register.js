const express = require("express");

let router = express.Router();

router.get("/", (req, res) => {
  //设置session
  req.session.username = "trafal";
  res.send("注册");
});
module.exports = router;
