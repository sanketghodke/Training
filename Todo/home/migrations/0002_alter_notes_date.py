# Generated by Django 3.2.14 on 2022-07-21 02:38

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('home', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='notes',
            name='date',
            field=models.DateField(blank=True, null=True),
        ),
    ]
