let mongoose = require('mongoose');

mongoose.connect('mongodb://trafal:991220@localhost:27017/trafal',{ useNewUrlParser: true,useUnifiedTopology: true},err=>{
    if (err) {
        console.log(err);
        return;
    }
    console.log('SUCCESS TO CONNECT')
})

let userSchema = mongoose.Schema({
    name:String,
    age:{
        type:Number,
        default:9999 //设置默认参数
    },
})

let userModel = mongoose.model('User',userSchema,"users");



let user = new userModel({
    name:"王五",

})
user.save((err,doc)=>{
    if(err){
    console.log(err)
    return;
    }
    console.log(doc)
})



//查找
userModel.find({},function(err,doc){
    if (err) {
            console.log(err)
            return;
        }
        console.log(doc);
})