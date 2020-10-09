const express = require("express");
const multer = require('multer');
const path = require('path');

let storage = multer.diskStorage({
  destination:function (req,file,cb){cb(null,'/static/upload')},
  filename:function(req,file,cb){
    let extname = path.extname(file.originalname);
    cb(null,Date.now()+extname);
  }
});
let upload = multer(
  { storage:storage }
)


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
router.post("/doUpload",upload.single('pic'),function (req, res) {
  // res.render("doUpload", {}, (err, data) => {
  //   if (err) {
  //     console.log("fail to  upload");
  //     return; 
  //   }
    res.send(JSON.stringify({
      body:req.body,
      file:req.file
    }));
  // });
  console.log(req.body);
});

module.exports = router;
