const multer = require('multer');
const path = require('path');
const sd = require('silly-datetime');
const mkdirp = require('mkdirp');


let tools = {
    multer(){
        let storage = multer.diskStorage({
            destination:async function (req,file,cb){
                //获取当前日期
                let day = sd.format(new Date(),"YYYYMMDD");
                //生成 static/upload/20200703
                let dir = path.join("static/upload",day);
                //按照日期生成图片存储目录
                await mkdirp(dir) //该方法是异步方法
                cb(null,dir);
            },
            filename:function(req,file,cb){
              let extname = path.extname(file.originalname);
              cb(null,Date.now()+extname);
            }
          });
          let upload = multer(
            { storage:storage }
          )

          return upload;
    },
    md5(){},

}

module.exports = tools;