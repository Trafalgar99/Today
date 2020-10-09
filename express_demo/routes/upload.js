const express = require("express");
const  tools = require('../model/tools');

let router = express.Router();

router.get("/", function (req, res) {
  res.render("upload", {}, (err, data) => {
    if (err) {
      console.log("fail to render upload");
      return;
    }
    res.send(data);
  });
});
router.post("/doUpload",tools.multer().single('pic'),function (req, res) {
  res.render("doUpload", {}, (err, data) => {
    if (err) {
      console.log("fail to  upload");
      return; 
    }
    res.send(JSON.stringify({
      body:req.body,
      file:req.file
    }));
  // });
  console.log(req.body);
});
})
module.exports = router;
