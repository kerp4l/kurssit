var TestUser = require('./models/test_user');
var BlogPost = require('./models/blog_post');

//Set up mongoose connection
var mongoose = require('mongoose');
var mongoDB = 'mongodb+srv://kerpaldb:88ada812a3@cluster0-h3iz7.mongodb.net/local_library?retryWrites=true&w=majority';
mongoose.connect(mongoDB, { useNewUrlParser: true });
var db = mongoose.connection;
db.on('error', console.error.bind(console, 'MongoDB connection error:'));



var the_text = "This is going to be the newest post.";


var  blog_post = new BlogPost({username: 'user3', blog_content: the_text});
	
blog_post.save(function (err) {
  if (err) return handleError(err);
  // saved!
});


