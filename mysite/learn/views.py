from django.shortcuts import render

# Create your views here.
#coding:utf-8
from django.shortcuts import render
import time

def GetNowTime():
    return time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(time.time()))

def home(request):
    string = u"home";
    print(string);
    return render(request, 'home.html', {'time': time});
