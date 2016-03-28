var polling = {
	updateInterval: 1000,
	mirrorUrl:'http://localhost:8000/',
	pictrueUrl:'http://localhost:8000/pictrue',
	oldMode:'',
}

polling.update = function () {
	//alert("pollingtest");
        var a = 1;
        var b = 2;
        $.get("/polling/",{'a':a,'b':b}, function(result){
			if(result.mode==1&&polling.oldMode==2){
				polling.oldMode=1;
				window.location.href='http://localhost:8000/';
			}else if(result.mode==2&&polling.oldMode==1){
				polling.oldMode=2;
				window.location.href='http://localhost:8000/pictrue';
			}
            $('#test').html(result.time);
        })
      

}

polling.init = function (mode) {
	//alert(mode);
	polling.oldMode=mode;
	this.intervalId = setInterval(function () {
		this.update();
	}.bind(this), this.updateInterval);
	this.update();
}
