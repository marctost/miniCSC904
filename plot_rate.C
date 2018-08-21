#include "snippet.C"
#include <vector>
#include "plotting_functions.h"
#include "root_tools.h"
#include "rate_labeling.h"

int graph_section(TString which_chamber, string filename, PlotterLines graphLines, PlotterLines subtraction, string subtract_or_no, string irr_or_ref, string type, int line_num);

void plot_rate(TString which_chamber, string which_plot, string subtract_or_no, string irr_or_ref, string type, int line_num) {
    ExcelSheet test(which_chamber+"/"+"final_numbers_rate.csv");
    
    
    // This is the important bit! The first value (test) refers to the excel sheet above. The second number is
    // the row your numbers start on. The second number is the lowest row you go to. The 3rd number is the first column that you're pulling data from. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines ALCT_dark(test, 2, 27, 2, line_num);
    PlotterLines CLCT_dark(test, 2, 27, 14, line_num);
    PlotterLines LCT_dark(test, 2, 27, 26, line_num);
    
    PlotterLines ALCT_top_irr(test, 94, 119, 2, line_num);
    PlotterLines CLCT_top_irr(test, 94, 119, 14, line_num);
    PlotterLines LCT_top_irr(test, 94, 119, 26, line_num);

    PlotterLines ALCT_top(test, 33, 58, 2, line_num);
    PlotterLines CLCT_top(test, 33, 58, 14, line_num);
    PlotterLines LCT_top(test, 33, 58, 26, line_num);

    PlotterLines ALCT_bottom(test, 64, 89, 2, line_num);
    PlotterLines CLCT_bottom(test, 64, 89, 14, line_num);
    PlotterLines LCT_bottom(test, 64, 89, 26, line_num);
    
    
    // Choose which plot you do. All the different options have their own call in the bash script.
    
    if (which_plot=="ALCT_dark"){
        graph_section(which_chamber, which_plot,ALCT_dark, ALCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="ALCT_top"){
        graph_section(which_chamber, which_plot,ALCT_top, ALCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="ALCT_bottom"){
        graph_section(which_chamber, which_plot,ALCT_bottom, ALCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="ALCT_top_irr"){
        graph_section(which_chamber, which_plot,ALCT_top_irr, ALCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="CLCT_dark"){
        graph_section(which_chamber, which_plot,CLCT_dark, CLCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="CLCT_top"){
        graph_section(which_chamber, which_plot,CLCT_top, CLCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="CLCT_bottom"){
        graph_section(which_chamber, which_plot,CLCT_bottom, CLCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="CLCT_top_irr"){
        graph_section(which_chamber, which_plot,CLCT_top_irr, CLCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="LCT_dark"){
        graph_section(which_chamber, which_plot,LCT_dark, LCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="LCT_top"){
        graph_section(which_chamber, which_plot,LCT_top, LCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="LCT_bottom"){
        graph_section(which_chamber, which_plot,LCT_bottom, LCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    else if (which_plot=="LCT_top_irr"){
        graph_section(which_chamber, which_plot,LCT_top_irr, LCT_dark, subtract_or_no, irr_or_ref, type, line_num);
    }
    
}



int graph_section(TString which_chamber, string filename, PlotterLines graphLines, PlotterLines subtraction, string subtract_or_no, string irr_or_ref, string type, int line_num){
	
    TString title = get_title(subtract_or_no, irr_or_ref, type);

    Color_t colors_used[] = {kRed, kRed+2, kBlue, kBlue+3};
    float color_trans[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    
    
    // The accumulated charge of each run, used to make the legend
    TString acc_charges[] = {", 0 mC/cm", ", 53 mC/cm", ", 95 mC/cm", ", 121 mC/cm", ", 149 mC/cm", ", 180 mC/cm", ", ? mC/cM", ", ? mC/cM", ", ? mC/cM", ", ? mC/cM", ", ? mC/cM", ", ? mC/cM", ", ? mC/cM", ", ? mC/cM"};


    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(23);


	//make the canvas, set its properties
    TCanvas *canvas = rate_plotting(graphLines, subtraction, subtract_or_no, irr_or_ref, line_num, colors_used, color_trans, acc_charges, title);
	canvas->cd();

    
    // Add a line at 3.6 kV
    canvas->Update();
    TLine *line = new TLine(3.6, 0, 3.6, 500);
    line->SetLineColor(kPink-9);
    line->SetLineWidth(2.0);
    line->Draw();


    // Save the plot.
    system("mkdir -p "+which_chamber+"/"+"Plots/");
    TString saveWhere;
    if (irr_or_ref=="dark"){
        saveWhere = which_chamber+"/"+"Plots/"+filename+".pdf";
    }
    else{
        saveWhere = which_chamber+"/"+"Plots/"+filename+"_"+subtract_or_no+".pdf";
    }
	canvas->Update();
    canvas->SaveAs(saveWhere);
    canvas;


	return 0;
}
