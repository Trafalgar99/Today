//模块化简化mongoose操作过程

let userModel = require('./model/user');

userModel.find({},(err,doc)=>{
    if (err) {
            console.log(err);
            return;
        }
        console.log(doc);
})