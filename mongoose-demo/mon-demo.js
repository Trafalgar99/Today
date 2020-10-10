const mongoose = require('mongoose');

//建立连接
mongoose.connect('mongodb://trafal:991220@127.0.0.1:27017/trafal',{ useUnifiedTopology: true,useNewUrlParser: true },err=>{
    if (err) {
            console.log(err);
            return;
        }
        console.log("success to connect")
        
})

// 操作集合   定义一个schema schema里面的对象和数据库表里面的字段要一一对应

let userSchema = mongoose.Schema({
    name:String,
    age:Number,
})

//定义数据库模型， 操作数据库
//model里面的第一个参数 要注意 1.首字母大写 2.要和数据库表（集合名称）对应
let user = mongoose.model('user',userSchema); //在第三个参数位置再写一个user则是选择和单数user连接

//查询users表的数据
// user.find({},function(err,doc){
//     if(err){
//         console.log(err);
//         return;
//     }
//     console.log(doc);
// })

//增加数据

//实例化model -- 通过实例化user 创建怎加的数据

// let u = new user({
//     name:"李四", 
//     age:20
// });
// u.save(function(err){
//     if(err){
//         console.log(err);
//         return;
//     }
//     console.log('success')
// }) // 执行增加操作

//更新数据

//定义操作数据库的model
// user.updateOne({"_id":"5f81075f8b8e5033909c23be"},{name:"张三"},function(err,doc){
//     if(err) return console.log(err);
//     console.log(doc);
// })

//删除数据
// user.deleteOne({"_id":"5f81075f8b8e5033909c23be"},(err,doc)=>{
//         if(err) return console.log(err);
//         console.log(doc);
// })