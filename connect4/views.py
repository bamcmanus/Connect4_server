from django.shortcuts import render
from django.http import HttpResponseRedirect

def homeView(request):
#    return HttpResponse('Welcome to Connect 4 Home page')
    return render(request,'index.html')

def selectView(request):
    return render(request, 'select.html')

def newGame(request):
    return HttpResponseRedirect('/select/')

def onePlayer(request):
    return HttpResponseRedirect('/play/')

def twoPlayer(request):
    return HttpResponseRedirect('/play/')

def play(request):
    return render(request, 'game.html')