//连接数据库
let mongoose = require('mongoose');

mongoose.connect('mongodb://trafal:991220@localhost:27017/trafal',{ useNewUrlParser: true,useUnifiedTopology: true},err=>{
    if (err) {
        console.log(err);
        return;
    }
    console.log('SUCCESS TO CONNECT')
})

module.exports=mongoose;