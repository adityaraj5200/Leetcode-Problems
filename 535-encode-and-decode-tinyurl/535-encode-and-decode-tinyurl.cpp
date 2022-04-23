class Solution {
private:
	const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    map<string,string> url_code, code_url;
    random_device rd;
    
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        while(code=="" || code_url.count(code)){
            code = "";
            for(int i=0;i<6;i++)
                code += charset[rd()%charset.size()];
        }
        
        code_url[code] = longUrl;
        url_code[longUrl] = code;
        
        return "https://tinyurl.com/" +  code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code_url[shortUrl.substr(20)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));