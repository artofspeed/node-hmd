var hmd = require("../.."),
	express = require("express"),
	http = require("http");

// Create HMD manager object
var manager = hmd.createManager("default");

// Instantiate express server
var app = express();
app.set('port', process.env.PORT || 3000);

// Set up request routing
app.get("/", function (req, res) {
	res.sendfile(__dirname + "/index.html");
});

app.get("/supported", function (req, res) {
	res.json(hmd.getSupportedDevices());
});

app.get("/info", function (req, res) {
	manager.getDeviceInfo(function(err, deviceInfo) {
		res.json(deviceInfo);
	});
});

app.get("/orientation", function (req, res) {
	manager.getDeviceOrientation(function(err, deviceOrientation) {
		res.json(deviceOrientation);
	});
});

// Launch express server
http.createServer(app).listen(app.get("port"), function () {
	console.log("Express server listening on port " + app.get("port"));
});