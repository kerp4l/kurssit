var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var TestUserSchema = new Schema(
	{
	username: {type: String, unique: true, required: true, min: 3, max: 15},
	password: {type: String, required: true, min: 5, max: 20},
	}
);

//Export model
module.exports = mongoose.model('TestUser', TestUserSchema);

