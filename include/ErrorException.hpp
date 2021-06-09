#ifndef ErrorException_HPP
# define ErrorException_HPP

# include <exception>
# include <string>

class ErrorException
{
private:
	std::string reason;
public:
	ErrorException(const char *reason) : reason(reason)
	{}
	virtual const char* what() const
	{
		std::string message = "Error occured - " + reason;
		const char *result = message.c_str();
		
		return (result);
	}
};

#endif