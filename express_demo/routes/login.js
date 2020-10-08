const express = require("express");

let router = express.Router();
router.get("/", (req, res) => {
  res.render("login", {}, function (err, data) {
    if (err) console.log(err);
    res.send(data);
  });
});

router.post("/doLogin", (req, res) => {
  res.render("doLogin", {}, function (err, data) {
    res.send(data);
  });
  console.log(req.body);
});

module.exports = router;
