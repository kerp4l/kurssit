var express = require('express');
var router = express.Router();

// Require controller module.
var blog_post_controller = require('../controllers/blogPostController');


/* GET home page. */
router.get( '/', blog_post_controller.count_posts);


/*Get most recent posts  and search form*/
router.get('/posts', blog_post_controller.recent_posts);


/*Search and display posts by other users*/
router.post('/posts', blog_post_controller.search_posts);


router.get('/create_post', function(req, res, next) {
	res.render('create_post');
});



module.exports = router;
