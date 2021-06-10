#include <iostream>
#include <gtest/gtest.h>
//Test functions
#include "ConfigParser.hpp"

//ConfigParser
TEST(ConfigParser, fileToString)
{
	ConfigParser parser;
	//Test1. fileToString
	std::string str = parser.fileToString("./test_res/configparser/file1");
	std::string str_cmp = "server { #comment1\nlocation / #comment2\n\t{ #comment3\n\t\tallow GET POST; #comment4\n\t\troot /www/; #comment5\n\t} #comment6\n} #comment7";
	ASSERT_STREQ(str.c_str(),str_cmp.c_str());
}

TEST(ConfigParser, eraseComment)
{
	ConfigParser parser;
	std::string str = parser.fileToString("./test_res/configparser/file1");
	parser.eraseComment(str);
	std::string str_cmp = "server { \nlocation / \n\t{ \n\t\tallow GET POST; \n\t\troot /www/; \n\t} \n} ";
	ASSERT_STREQ(str.c_str(),str_cmp.c_str());
}

TEST(ConfigParser, stringToToken)
{
	ConfigParser parser;
	std::string str = parser.fileToString("./test_res/configparser/file1");
	parser.eraseComment(str);

	std::vector<std::string> token = parser.stringToToken(str);
	std::string token_array[] =
	{"server","{","location","/","{","allow","GET","POST;","root","/www/;","}","}"};
	std::vector<std::string> token_cmp;
	for (int i = 0; i < 12; ++i)
		token_cmp.push_back(token_array[i]);
	for (int i =0; i < 12; ++i)
		EXPECT_STREQ(token[i].c_str(), token_cmp[i].c_str());
	EXPECT_EQ(token.size(), token_cmp.size());
}

TEST(ConfigParser, parselistenPort)
{
	ConfigParser parser;
	std::vector<std::string> tokens;
	tokens.push_back("listen");
	tokens.push_back("8080;");
	EXPECT_EQ(parser.parselistenPort(tokens.begin()), 8080);
}

TEST(ConfigParser, parseWorkerConnection)
{
	ConfigParser parser;
	std::vector<std::string> tokens;
	tokens.push_back("worker_connection");
	tokens.push_back("4096;");
	EXPECT_EQ(parser.parselistenPort(tokens.begin()), 4096);
}

TEST(ConfigParser, parseOnlyOneStringToken)
{
	ConfigParser parser;
	std::vector<std::string> tokens;
	tokens.push_back("server_name");
	tokens.push_back("abcdefg;");
	EXPECT_STREQ(parser.parseOnlyOneStringToken(tokens.begin()).c_str(), "abcdefg");
}

TEST(ConfigParser, parseErrorPage)
{
	ConfigParser parser;
	std::vector<std::string> tokens;
	std::vector<std::string> tokens2;
	std::map<int, std::string> error_page;
	tokens.push_back("error_page");
	tokens.push_back("404");
	tokens.push_back("405");
	tokens.push_back("406");
	tokens.push_back("/www/404error.html;");
	parser.parseErrorPage(tokens.begin(), error_page);
	tokens2.push_back("error_page");
	tokens2.push_back("404");
	tokens2.push_back("501");
	tokens2.push_back("/www;");
	parser.parseErrorPage(tokens2.begin(), error_page);
	ASSERT_STREQ(error_page[404].c_str(), "/www/404error.html");
	ASSERT_STREQ(error_page[405].c_str(), "/www/404error.html");
	ASSERT_STREQ(error_page[406].c_str(), "/www/404error.html");
	ASSERT_STREQ(error_page[501].c_str(), "/www");
	ASSERT_EQ(error_page.size(), 4);
}

TEST(ConfigParser, parseLocation)
{
	ConfigParser parser;
	std::vector<std::string> tokens;
	tokens.push_back("location");
	tokens.push_back("/webserv/");
	ASSERT_STREQ(parser.parseLocation(tokens.begin()).c_str(), "/webserv/");
}

TEST(ConfigParser, parseIndexList)
{
	ConfigParser parser;
	std::vector<std::string> tokens;
	std::vector<std::string> index;
	tokens.push_back("index");
	tokens.push_back("index.html");
	tokens.push_back("index.php;");
	index = parser.parseIndexList(tokens.begin());
	ASSERT_STREQ(index[0].c_str(), "index.html");
	ASSERT_STREQ(index[1].c_str(), "index.php");
}

TEST(ConfigParser, parseAllow)
{
	ConfigParser parser;
	std::vector<std::string> tokens;
	std::vector<std::string> method;
	tokens.push_back("allow");
	tokens.push_back("GET");
	tokens.push_back("POST;");
	method = parser.parseIndexList(tokens.begin());
	ASSERT_STREQ(method[0].c_str(), "GET");
	ASSERT_STREQ(method[1].c_str(), "POST");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}