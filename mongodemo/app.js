const { MongoClient } = require("mongodb"); // 引入mongodb下的mongoclient

//定义数据库连接的地址
const url = "mongodb://trafal:991220@127.0.0.1:27017/trafal";

//定义要操作的数据库
const dbName = "trafal";

//实例化MongoClient 传入数据库链接地址
const client = new MongoClient(url, { useUnifiedTopology: true });

// 链接数据库
client.connect((err) => {
  if (err) {
    console.log("fail to connect database!");
    return;
  }
  console.log("success to connect database");

  //获取要操作的数据库
  let db = client.db(dbName);

  //查找数据
  db.collection("user")
    .find({})
    .toArray((err, data) => {
      console.log(data);

      //操作数据库完毕以后一定要关闭数据库链接
      client.close();
    });

  //   //增加数据
  //   db.collection("user").insertOne(
  //     { username: "nodejs操作mongodb", age: 10 },
  //     (err, result) => {
  //       if (err) {
  //         //增加失败
  //         console.log(err);
  //         return;
  //       }

  //       console.log("success to insert data");
  //       console.log(result);

  //       //操作数据库完毕以后一定要关闭数据库链接
  //       client.close();
  //     }
  //   );
  //   //修改数据
  //   db.collection("user").updateOne(
  //     { name: "trafal1" },
  //     { $set: { age: 99 } },
  //     (err, result) => {
  //       if (err) {
  //         //修改失败
  //         console.log(err);
  //         return;
  //       }

  //       console.log("success to update");
  //       console.log(result);

  //       //操作数据库完毕以后一定要关闭数据库链接
  //       client.close();
  //     }
  //   );

  //   //删除数据
  //   db.collection("user").deleteOne({ name: "trafal2" }, (err) => {
  //     if (err) {
  //       console.log(err);
  //       return;
  //     }
  //     console.log("success to delete an item");
  //   });

  //   //删除多条数据
  //   db.collection("user").deleteMany({ name: "trafal2" }, (err) => {
  //     if (err) {
  //       console.log(err);
  //       return;
  //     }
  //     console.log("success to delete  items");
  //     client.close();
  //   });
});
