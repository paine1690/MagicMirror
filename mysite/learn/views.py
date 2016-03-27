# Create your views here.
#coding:utf-8
from django.shortcuts import render
from django.http import HttpResponse
import time

int1=0;
def GetNowTime():
    return time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(time.time()))

def home(request):
    string = u"home";
    print(string);
    return render(request, 'home.html', {'time': time});
	

def pictrue(request):
    string = u"pictrue";
    print(string);
    return render(request, 'pictrue.html');


def polling(request):
    string = u"polling";
    print(string);
    i=+1;
    if i%2 ==0:
        return HttpResponse("ji");	
    else:
        return HttpResponse("ou");	
    
	
