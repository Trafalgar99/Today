var app = new Vue({
    el:"#player",
    data:{
        query: '',
        musicList:[],
        musicUrl:'',
        coverUrl:"",
        commentList:[],
        isPlaying:false,
        isShow:false,
        mvUrl:"",
    },
    methods:{
        searchMusic:function(){
            axios.get(`https://autumnfish.cn/search?keywords=${this.query}`)
            .then(res=>{
                this.musicList = res.data.result.songs;
                // console.log(res.data.result.songs)
            },err=>console.log(err));
        },
        playMusic:function (musicId) {
            axios.get(`https://autumnfish.cn/song/url?id=${musicId}`)
            .then(res=>this.musicUrl=res.data.data[0].url,err=>console.log(err))
        },
        changeCover:function(coverId){
            axios.get(`https://autumnfish.cn/song/detail?ids=${coverId}`)
            .then(res=>this.coverUrl = res.data.songs[0].al.picUrl,err=>console.log(err))            
        },
        getComment:function(musicId){
            axios.get(`https://autumnfish.cn/comment/hot?type=0&id=${musicId}`)
            .then(res=>{
                // console.log(res)
                this.commentList = res.data.hotComments
            },err=>console.log(err)) 
        },
        play:function(){
            this.isPlaying = true;
        },
        pause:function(){
            this.isPlaying = false;
        },
        playMV:function(mvid){
            axios.get(`https://autumnfish.cn/mv/url?id=${mvid}`)
            .then(res=>{
                // console.log(res)
                this.isShow=true;
                this.mvUrl = res.data.data.url;
            },err=>console.log(err))
        },
        hide:function(){
            this.isShow=false;
            this.mvUrl = ""
        }
    }
})
//this.comment_list = res.data.hotComments