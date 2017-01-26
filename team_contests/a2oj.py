import requests
import re
import urllib
s = requests.session()
payload = {'Username':'saikrishna17394','Password':'17031994'}
url = 'http://a2oj.com/SignInCode.jsp' 
r = s.post(url,payload)
##################################################################
contest = 13628
start = 4944
end = 4953
##################################################################
for q in range(start,end+1):
    print('http://a2oj.com/Problems.jsp?q='+str(q))
    response = s.get('http://a2oj.com/Problems.jsp?q='+str(q))
    problem = re.search('.*Live Archive.*',response.text).group(0)
    print(problem)
    problem = urllib.parse.quote_plus(problem)
    response = s.get('http://a2oj.com/SpecificProblemsCode.jsp?ID='+str(contest)+'&Judge=LA&Problem='+problem)
