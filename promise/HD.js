class HD {
  static PENDING = "pending";
  static FULFILLED = "fulfilled";
  static REJECTED = "rejected";
  constructor(executor) {
    console.log(this);
    this.status = HD.PENDING;
    this.value = null;
    this.callbacks = [];
    try {
      executor(this.resolve.bind(this), this.reject.bind(this));
    } catch (error) {
      this.reject(error);
    }
  }

  //resolve reject
  resolve(value) {
    if (this.status == HD.PENDING) {
      this.status = HD.FULFILLED;
      this.value = value;
      setTimeout(() => {
        this.callbacks.map((callback) => {
          callback.onFulfilled(value);
        });
      }, 0);
    }
  }
  reject(reason) {
    if (this.status == HD.PENDING) {
      this.status = HD.REJECTED;
      this.value = reason;
      setTimeout(() => {
        this.callbacks.map((callback) => {
          callback.onRejected(reason);
        });
      }, 0);
    }
  }

  //then
  then(onFulfilled, onRejected) {
    if (typeof onFulfilled != "function") {
      onFulfilled = () => {
        return this.value;
      };
    }
    if (typeof onRejected != "function") {
      onRejected = () => {
        return this.value;
      };
    }
    //支持链式操作
    let promise = new HD((resolve, reject) => {
      //如果promise里面的是异步代码，则then应该排在其后面
      if (this.status == HD.PENDING) {
        // console.log("+++pending+++");
        this.callbacks.push({
          onFulfilled: (value) => {
            this.parse(promise, onFulfilled(value), resolve, reject);
          },
          onRejected: (value) => {
            this.parse(promise, onRejected(value), resolve, reject);
          },
        });
      }
      // console.log(this.status);
      if (this.status == HD.FULFILLED) {
        setTimeout(() => {
          this.parse(promise, onFulfilled(this.value), resolve, reject);
        }, 0);
      }
      if (this.status == HD.REJECTED) {
        setTimeout(() => {
          this.parse(promise, onRejected(this.value), resolve, reject);
        }, 0);
      }
      // console.log(this.status);
    });
    return promise;
  }
  parse(result, resolve, reject) {
    if (promise == result) {
      throw new TypeError("Chaining cycle detected");
    }
    try {
      if (result instanceof HD) {
        result.then(resolve, reject);
      } else {
        resolve(result);
      }
    } catch (error) {
      reject(error);
    }
  }

  static resolve(value) {
    return new HD((resolve, reject) => {
      if (value instanceof HD) {
        value.then(resolve, reject);
      } else {
        resolve(value);
      }
    });
  }
  static reject(value) {
    return new HD((resolve, reject) => {
      reject(value);
    });
  }
  static all(promises) {
    const values = [];
    return new HD((resolve, reject) => {
      promises.forEach((promise) => {
        promise.then(
          (value) => {
            values.push(value);
            if (values.length == promises.length) {
              resolve(values);
            }
          },
          (reason) => {
            reject(reason);
          }
        );
      });
    });
  }

  static race(promises) {
    return new HD((resolve, reject) => {
      promises.map((promise) => {
        promise.then(
          (value) => {
            resolve(value);
          },
          (reason) => {
            reject(reason);
          }
        );
      });
    });
  }
}
