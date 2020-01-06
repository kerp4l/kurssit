var moment = require('moment');
var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var BlogPostSchema = new Schema(
	{
	username: {type: String, required: true, min: 3, max: 15},
	blog_content: {type: String, required: true, min: 1, max: 250},
	post_date: {type: Date, default: Date.now},
	}
);

BlogPostSchema
.virtual('post_date_formatted')
.get(function () {
	return moment(this.post_date).format('DD.MM.YYYY HH:mm');
});




//Export model
module.exports = mongoose.model('BlogPost', BlogPostSchema);

