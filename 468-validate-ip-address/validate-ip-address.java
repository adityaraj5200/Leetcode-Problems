class Solution {
    public String validIPAddress(String queryIP) {
        if(queryIP.length() > 0){
            if(isValidIPv4(queryIP)){
                return "IPv4";
            }
            if(isValidIPv6(queryIP)){
                return "IPv6";
            }
        }

        return "Neither";
    }

    private boolean isValidIPv4(String query){
        if(query.charAt(0) == '.' || query.charAt(query.length()-1) == '.'){
            return false;
        }
        String[] tokens = query.split("\\."); // stirng[]

        
        for(String token: tokens){
            System.out.print(token + " ");
        }
        if(tokens.length != 4){
            // System.out.println("here 1");
            return false;
        }

        for(String token: tokens){
            if(token.length()==0 || token.length()>3){
                // System.out.println("here 2");
                return false;
            }
            if(token.length()>1 && token.charAt(0)=='0'){
                // System.out.println("here 3");
                return false;
            }

            for(char ch: token.toCharArray()){
                if(!Character.isDigit(ch)){
                    // System.out.println("here 4");
                    return false;
                }
            }

            if(Integer.parseInt(token) > 255){
                // System.out.println("here 5");
                return false;
            }
        }

        return true;        
    }

    private boolean isValidIPv6(String query){
        if(query.charAt(0) == ':' || query.charAt(query.length()-1) == ':'){
            return false;
        }
        String[] tokens = query.split(":"); // stirng[]
        System.out.println("tokens.length() = " + tokens.length);
        if(tokens.length != 8){
            System.out.println("here 1");
            return false;
        }

        for(String token: tokens){
            if(token.length()==0 || token.length()>4){
                System.out.println("here 2");
                return false;
            }

            for(char ch: token.toCharArray()){
                if(!isHex(ch)){
                    System.out.println("here 4");
                    return false;
                }
            }
        }

        return true;    
    }

    private boolean isHex(char ch){
        return Character.isDigit(ch) || (ch>='a' && ch<='f') || (ch>='A' && ch<='F');
    }
}