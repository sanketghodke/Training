from asyncio import tasks
from email import message
from hashlib import new
from urllib import request
from django.shortcuts import render,redirect,get_object_or_404
from django.utils import timezone

from home.forms import NotesForm
from .models import Notes

# Create your views here.

def index(req):
    return render(req,'home/index.html')

def create_task(req):

    if req.method=="POST":
        form = NotesForm(req.POST)
        if form.is_valid():
            form.save()
            return redirect('home:index')
        else:
            print("else")
    else:
        form = NotesForm()
    return render(req,'home/create_task.html',{'form':form})
 
def delete_task(req,pk):
    Notes.objects.filter(id=pk).delete()
    tasks=Notes.objects.all()
    return render(req,'home/task_list.html',{'tasks':tasks})

def task_list(req):
    tasks=Notes.objects.all()
    return render(req,'home/task_list.html',{'tasks':tasks})

   
def edit_task(req,pk):
    task_added_already=get_object_or_404(Notes,pk=pk) 
    if req.method=='POST':
        form=NotesForm(req.POST,instance=task_added_already)
        if form.is_valid():
            form.save()
            return render(req,'home/index.html')
    else:
        form = NotesForm(instance=task_added_already)
    return render(req,'home/edit_task.html',{'form':form})



# def edit_feedback_question(request,pk):
#     course = get_object_or_404(FeedbackQuestion, pk=pk)
#     if request.method=='POST':
#         form = FeedbackForm(request.POST,instance=course)
#         if form.is_valid():
#             new_question=form.save()
#             new_question.save()
#             messages.success(request, 'Question Edited successfully!')
#             return render(request,'home/dashboard.html')
#     else:
#         form = FeedbackForm(instance=course)
#     return render(request,'home/feedback/create_edit_feedback_question.html',{'form':form})