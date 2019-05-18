# Setting up Github pages site locally with Jekyll

## Requirements:

Open terminal and check whether you have ruby installed:

    $ ruby --version

If ruby is not installed, then [Download Ruby](https://www.ruby-lang.org/en/downloads/)
and install the latest version.

Install bundler:

    $ gem install bundler

## Move to the appropriate branch containing the source code for the Jekyll blog:

Checkout to the **gh-pages-source** branch of this repository:

    $ git pull
    $ git checkout gh-pages-source

Make sure to do `$ git pull` before so that if you had cloned earlier, this branch would be fetched remotely.

## Install Jekyll using bundler:

Install Jekyll and other dependencies:

    $ bundle install

## Now, you can make any changes to the site that you want, e.g. adding a new post. Details are provided below in the [Getting started with Jekyll](#getting-started-with-jekyll) section.

## Build your local jekyll site:

    $ bundle exec jekyll serve

Now, the site would be accessible at `localhost:4000/Competitive_Coding`.

Since this project uses some external _Jekyll plugins_ that are not supported by _github-pages_, thus, we have this additional branch where we will build the site locally, and then the contents of **_site** directory generated after build are pushed to the **gh-pages** branch which actually is rendered by _github-pages_. Thus, the additional step follows:

## Getting your local changes pushed to github-pages
First, commit your changes into this branch. Use

    $ git add files

to stage the appropriate files, then

    $ git commit -m "commit message"

finally

    $ git push origin gh-pages-source

Now, move to the **_site** folder:

    $ cd _site

Since this folder is not included in git version control, as it is included in the *.gitignore* file, we follow the following steps:

First of all, empty its contents, since you should fetch them locally first to avoid conflicts, we can **build from jekyll again**.

Initialize a new git repository in the empty _site folder:

    $ git init

Add remote:

    $ git remote add origin https://github.com/username/Competitive_Coding.git

Replace your username in the URL, also if you have made any changes to the name of the repository, take them into account.

Set up a new branch named **gh-pages**

    $ git checkout -b gh-pages

Fetch from origin's gh-pages branch:

    $ git pull origin gh-pages

Now, go one directory back,

    $ cd ..

Again, build the site:

    $ bundle exec jekyll serve

This would overwrite the **_site** folder with the updated site contents.

Change directory again:

    $ cd _site

then as usual do `$ git add`, `$ git commit` and `$ git push`.

Finally, send pull requests for both the branches "gh-pages-source" as well as "gh-pages".

## Making further changes
It would now become very easy, no more installation required and switching between branches also made easy.

    $ git checkout gh-pages-source

Make required changes, like adding a new post.

Add, commit and push in the branches **gh-pages** and **gh-pages-source** after doing jekyll build.

Send a pull request for both the branches.

# Getting started with Jekyll
1. You can read the [Quick-start Guide](https://jekyllrb.com/docs/quickstart/).
2. Understand the basic [Directory structure](https://jekyllrb.com/docs/structure/).
3. Know about [Front Matter](https://jekyllrb.com/docs/frontmatter/) used in writing posts.
4. Finally, understand how to [write posts](https://jekyllrb.com/docs/posts/) and create a good one for yourself.
5. This project is using one plugin to include code directly from github repo in the blog post, its pretty straight-forward, read about it: [Jekyll Github Sample](https://github.com/bwillis/jekyll-github-sample/). You can read the sample post already present in the __posts_ directory in the **gh-pages-source** branch.

For any other help, refer to the official [Jekyll documentation](https://jekyllrb.com/docs/home/).
