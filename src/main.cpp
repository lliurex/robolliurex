
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>

#include <cairo.h>
#include <lgi-1.0/x11window.hpp>
#include <lgi-1.0/layer.hpp>
#include <lsf-1.0/utils.hpp>

#include <gtk/gtk.h>
 
#include "robocore.h"
#include "robowidgets.h"
#include "rsrcmanager.h"
#include "roboslot.h"
#include "robopilot.h"





using namespace std;
using namespace net::lliurex::lgi;
using namespace net::lliurex::robolliurex;



int main(int argc,char * argv[])
{
	/* locale setup */
	setlocale(LC_ALL,"");
	bindtextdomain("robolliurex","/usr/share/locale");
	textdomain("robolliurex");
	
	RoboCore * core = RoboCore::GetCore();
	core->Init();
	core->Run(LGI_DISPATCH_EVENTS_WAIT);
	
	RoboCore::Destroy();
}

/*
X11Window * window;
bool quit_request=false;



int crap(int argc,char * argv[])
{
	cairo_t * cairo;
	cairo_surface_t * srf_background;
	
	bool have_batt=false;
	float batt=0.0f;
	
	
	setlocale( LC_ALL, "" );
	bindtextdomain( "robolliurex", "/usr/share/locale" );
	textdomain( "robolliurex" );
	
	//g_type_init();
	gtk_init(&argc,&argv);
	
	window = new X11Window(800,600,0);
	RoboCore::GetCore()->window=window;
	
	
	vector<string>targets={"text/uri-list"};	
	window->SetDndTargets(targets);
	
	window->SetTitle("Robolliurex");
		
	
	window->AddLayer(new MainScreen());
	window->AddLayer(new SetupScreen());
	window->AddLayer(new PilotMenu());
	window->AddLayer(new COMScreen());
	window->AddLayer(new FirmwareScreen());
	window->AddLayer(new TestScreen());
	window->AddLayer(new DropScreen());
	window->AddLayer(new Pilot1());
	window->AddLayer(new Pilot2());
	window->AddLayer(new Pilot3());
	window->AddLayer(new Pilot4());
	
	cout<<"* Robolliurex"<<endl;
	
	srf_background = RoboCore::GetCore()->rsrc->GetSurface("blueprint.png");
	
	RawEvent * raw_event;
	int t;	
	int dp_events;
	bool is_idle;
	
	while(!quit_request)
	{
		
		
		//custom event dispatcher
	lbl_dispatch:
	
		t = window->GetTicks();
		
		dp_events=0;
		
		
		do
		{
			is_idle=false;
			window->GetEvent();
			raw_event=window->PopEvent();
			
			if(raw_event!=NULL)
			{
				dp_events++;
				is_idle=true;
				
				//catch messages
				if(raw_event->event->type==LGI_EVENT_MESSAGE)
				{
					MessageEvent * msge = (MessageEvent *)raw_event->event;
					
					if(msge->msg->id==RBW_MSG_BATTERY_STATUS)
					{
						have_batt=true;
						batt=((MessageDataFloat * )msge->msg->data["value"])->value;
					}
				}
				
				window->ProcessEvent(raw_event);
		
				//Free event
				delete raw_event->event;
				delete raw_event;
			}
			
			if(gtk_events_pending())
			{
				is_idle=true;
				dp_events++;
				gtk_main_iteration();
			}
		}while(is_idle);
			
		if(dp_events==0)
		{
			usleep(15000);
			goto lbl_dispatch;
		}
		
		
		cairo = window->cairo;
		
		cairo_set_source_surface(cairo,srf_background,0,0);
		cairo_paint(cairo);
		
		cairo_text_extents_t te;
		cairo_font_extents_t fe;
		
		stringstream ss;
		ss<<"Version: "<<VERSION;
		
		cairo_select_font_face (cairo, "Ubuntu", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
		cairo_set_font_size (cairo, 11.0);
		cairo_text_extents (cairo, ss.str().c_str(), &te);
		cairo_font_extents (cairo, &fe);
		
		cairo_surface_t * target = cairo_get_target(cairo);
		float width = cairo_image_surface_get_width(target);
		float height = cairo_image_surface_get_height(target);
		
		
		
		cairo_move_to (cairo,5.0f,height-fe.height);
		cairo_set_source_rgb (cairo, 0.95, 0.95, 0.95);
		cairo_show_text (cairo, ss.str().c_str());	
		
		if(have_batt)
		{
			ss.str("");
			ss<<"Batt: "<<std::setprecision(2) << std::fixed<<batt<<" V";
					
			cairo_move_to (cairo,width-te.width-3.0f,fe.height+3.0f);
			cairo_set_source_rgb (cairo, 0.95, 0.95, 0.95);
			cairo_show_text (cairo, ss.str().c_str());
		}
		
		
		window->Flip();
		//usleep(15000);
	}
	
	
	
	window->Destroy();
	
	
	delete window;
	RoboCore::Destroy();
	
	return 0;
}

*/
