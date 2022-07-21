from django.conf import settings
from django.db import models
from datetime import datetime

class Notes(models.Model):
    #can add multiple attributes without adding in database.
    author = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    note_title = models.CharField(max_length=200)
    note_detail = models.TextField()
    is_done = models.BooleanField(default=False)
    date = models.DateTimeField(default=datetime.now, null=True)


    def __str__(self):
        return self.note_title
        #CAN ALSO USE __repr__()
        # used for string inputs and outputs
        # to idesntify objects in debugging shell. It will return name of the title in the shelll output.