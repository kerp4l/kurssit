var User = require('./models/user');
var BlogPost = require('./models/blog_post');
const bcrypt = require('bcrypt');

//Set up mongoose connection
var mongoose = require('mongoose');
var mongoDB = 'mongodb+srv://db_user:foobar123@cluster0-tjvex.mongodb.net/posts_library?retryWrites=true&w=majority';
mongoose.connect(mongoDB, { useNewUrlParser: true });
var db = mongoose.connection;
db.on('error', console.error.bind(console, 'MongoDB connection error:'));


bcrypt.hash('user1', 10, function(err, hash) {

	var user = new User({username: 'user1', password: hash});
	
	user.save(function (err) {
	  if (err) return handleError(err);
	  // saved!
	});
});

