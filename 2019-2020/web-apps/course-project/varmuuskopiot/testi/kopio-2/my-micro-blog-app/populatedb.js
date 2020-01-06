var TestUser = require('./models/test_user');
var BlogPost = require('./models/blog_post');

//Set up mongoose connection
var mongoose = require('mongoose');
var mongoDB = 'mongodb+srv://db_user:foobar123@cluster0-tjvex.mongodb.net/posts_library?retryWrites=true&w=majority';
mongoose.connect(mongoDB, { useNewUrlParser: true });
var db = mongoose.connection;
db.on('error', console.error.bind(console, 'MongoDB connection error:'));



var the_text = "Wow! This is amazing  app."

var  blog_post = new BlogPost({username: 'user123', blog_content: the_text});
	
blog_post.save(function (err) {
  if (err) return handleError(err);
  // saved!
});


