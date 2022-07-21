from unicodedata import name
from django.urls import path
from . import views
app_name="home"

urlpatterns=[
    path('',views.index,name="index"),
    path('create_task/',views.create_task,name="create_task"),
    path('task_list/',views.task_list,name="task_list"),
    path('<int:pk>/delete_task',views.delete_task,name="delete_task"),
    path('<int:pk>/edit_task',views.edit_task,name="edit_task")
]