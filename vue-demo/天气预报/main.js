var app = new Vue({
    el:"#app",
    data:{
        city:'',
        weatherList:[]
    },
    methods:{
        searchWeather:function(){
             axios.get(`http://wthrcdn.etouch.cn/weather_mini?city=${this.city}`)
             .then(res=>this.weatherList = res.data.data.forecast).catch(err=>console.log(err))
        },
        changeCity:function (city) {
            this.city = city;
            axios.get(`http://wthrcdn.etouch.cn/weather_mini?city=${this.city}`)
             .then(res=>this.weatherList = res.data.data.forecast).catch(err=>console.log(err))
        }
    }
})
// 