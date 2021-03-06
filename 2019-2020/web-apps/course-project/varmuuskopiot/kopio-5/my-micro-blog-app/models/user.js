var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var UserSchema = new Schema(
	{
	username: {type: String, unique: true, required: true, min: 3, max: 15},
	password: {type: String, required: true},
	}
);

//Export model
module.exports = mongoose.model('User', UserSchema);

