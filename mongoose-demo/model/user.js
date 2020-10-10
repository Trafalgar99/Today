let mongoose = require('./db.js')

let userSchema = mongoose.Schema({
    name:String,
    age:{
        type:Number,
        default:9999 //设置默认参数
    },
})

let userModel = mongoose.model('User',userSchema,'users');

module.exports =  userModel;