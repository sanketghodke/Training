from django import forms
from .models import *
from django.contrib.auth.models import User

class NotesForm(forms.ModelForm):
    class Meta:
        model=Notes
        exlude=['date']
        fields=['author','note_title','note_detail','is_done']