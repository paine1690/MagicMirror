var polling = {
	
	updateInterval: 1000,
	
}

polling.update = function () {
	//alert("pollingtest");
        var a = 1;
        var b = 2;
        $.get("/polling/",{'a':a,'b':b}, function(ret){
            $('#test').html(ret)
        })
      

}

polling.init = function () {

	this.intervalId = setInterval(function () {
		this.update();
	}.bind(this), this.updateInterval);
	this.update();
	
	
}
