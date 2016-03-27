from django.conf.urls import patterns, include, url

from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
    url(r'^$','learn.views.home', name='home'),
	url(r'^mirror','learn.views.home', name='home'),
	url(r'^pictrue','learn.views.pictrue'),
	url(r'^polling/$', 'learn.views.polling', name='polling'),
    url(r'^admin/', include(admin.site.urls)),
)
