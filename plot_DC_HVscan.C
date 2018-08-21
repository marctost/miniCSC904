#include "snippet.C"
#include "plotting_functions.h"
#include "root_tools.h"

int graph_section(TString which_chamber, string filename, vector<PlotterLines> run);


void plot_DC_HVscan(TString which_chamber, string which_plot) {
    ExcelSheet test(which_chamber+"/"+"analysis_page_darkCurrent.csv");
    
    // This is the inportant bit! The first value refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. The 3rd number is the first column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines irr_0(test, 3, 10, 0, 2);
    PlotterLines ref_0(test, 3, 6, 2, 2);
    
    PlotterLines irr_1(test, 3, 9, 5, 2);
    PlotterLines ref_1(test, 3, 6, 7, 2);
    
    PlotterLines irr_2(test, 3, 10, 10, 2);
    PlotterLines ref_2(test, 3, 6, 12, 2);
    
    PlotterLines irr_3(test, 3, 10, 15, 2);
    PlotterLines ref_3(test, 3, 6, 17, 2);
    
    PlotterLines irr_4(test, 3, 10, 20, 2);
    PlotterLines ref_4(test, 3, 6, 22, 2);

    PlotterLines irr_5(test, 3, 10, 25, 2);
    PlotterLines ref_5(test, 3, 6, 27, 2);
    
    PlotterLines irr_6(test, 3, 10, 30, 2);
    PlotterLines ref_6(test, 3, 6, 32, 2);
    
    PlotterLines irr_7(test, 3, 10, 35, 2);
    PlotterLines ref_7(test, 3, 6, 37, 2);
    
    PlotterLines irr_8(test, 3, 10, 40, 2);
    PlotterLines ref_8(test, 3, 6, 42, 2);
    
    PlotterLines irr_9(test, 3, 10, 45, 2);
    PlotterLines ref_9(test, 3, 6, 47, 2);
    
    PlotterLines irr_10(test, 3, 10, 50, 2);
    PlotterLines ref_10(test, 3, 6, 52, 2);
    
    
    vector<PlotterLines> irr;
    vector<PlotterLines> ref;
    
    irr.push_back(irr_0); irr.push_back(irr_1); irr.push_back(irr_2); irr.push_back(irr_3); irr.push_back(irr_4); irr.push_back(irr_5); irr.push_back(irr_6); irr.push_back(irr_7); irr.push_back(irr_8); irr.push_back(irr_9); irr.push_back(irr_10);
    
    ref.push_back(ref_0); ref.push_back(ref_1); ref.push_back(ref_2); ref.push_back(ref_3); ref.push_back(ref_4); ref.push_back(ref_5); ref.push_back(ref_6); ref.push_back(ref_7); ref.push_back(ref_8); ref.push_back(ref_9); ref.push_back(ref_10);
    
    
    // Choose which plot you want to make, bash script contains corresponding calls for each.
    if (which_plot=="irr"){
        graph_section(which_chamber, which_plot,irr);
    }
    else if (which_plot=="ref"){
        graph_section(which_chamber, which_plot,ref);
    }
}



int graph_section(TString which_chamber, string filename, vector<PlotterLines> run){

    Color_t color_irr[] = {kRed, kRed+2};
    Color_t color_ref[] = {kBlue, kBlue+3};
    Color_t old_color=color_irr[0];
    Color_t new_color=color_irr[1];
    
    TString title;
    TString label;
    label = "Irradiated layer";

    
    // If statements control the title of the graph
    if (filename=="ref"){
        label = "Reference layer";
        old_color=color_ref[0];
        new_color=color_ref[1];
    }
    
    title = "Dark Current: "+label;

    
    //Make sure that the vectors have the right length using the resize function
    vector<PlotterLines> line;
    for (int i=0; i<run.size(); i++){
        line.push_back(resize_DC(run[i]));
    }
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(23);

    TCanvas *canvas = make_canvas();
    TLegend *legend = make_legend();
	canvas->cd();


    // This function takes the line (which has been correctly sized), and then loops through and returns graphs.
    TGraph* graph_0_ = make_graph_DC_HV(line[0]);
    TGraph* graph_1_ = make_graph_DC_HV(line[1]);
    TGraph* graph_2_ = make_graph_DC_HV(line[2]);
    TGraph* graph_3_ = make_graph_DC_HV(line[3]);
    TGraph* graph_4_ = make_graph_DC_HV(line[4]);
    TGraph* graph_5_ = make_graph_DC_HV(line[5]);
//    TGraph* graph_6_ = make_graph_DC_HV(line[6]);
    //TGraph* graph_7_ = make_graph_DC_HV(line[7]);
    //TGraph* graph_8_ = make_graph_DC_HV(line[8]);
    //TGraph* graph_9_ = make_graph_DC_HV(line[9]);
    //TGraph* graph_10_ = make_graph_DC_HV(line[10]);
    
    
    //This is where the lines get their colors. The last number is the transparency. THe most recent run should get the color "new_color" and a transparency of 1.
    TGraph* graph_0 = format_me_DC(graph_0_, old_color,0.1);
    TGraph* graph_1 = format_me_DC(graph_1_, old_color,0.2);
    TGraph* graph_2 = format_me_DC(graph_2_, old_color,0.3);
    TGraph* graph_3 = format_me_DC(graph_3_, old_color,0.4);
    TGraph* graph_4 = format_me_DC(graph_4_, old_color,0.5);
    TGraph* graph_5 = format_me_DC(graph_5_, new_color,1);
//    TGraph* graph_6 = format_me_DC(graph_6_, new_color, 1);
    //TGraph* graph_7 = format_me_DC(graph_7_, old_color,0.8);
    //TGraph* graph_8 = format_me_DC(graph_8_, old_color,0.9);
    //TGraph* graph_9 = format_me_DC(graph_9_, old_color,1);
    //TGraph* graph_10 = format_me_DC(graph_10_, new_color,1);
    
    // Label the legend by hand
    legend->AddEntry(graph_0, "Run 0, 0 mC/cm");
    legend->AddEntry(graph_1, "Run 1, 53 mC/cm");
    legend->AddEntry(graph_2, "Run 2, 95 mC/cm");
    legend->AddEntry(graph_3, "Run 3, 121 mC/cm");
    legend->AddEntry(graph_4, "Run 4, 149 mC/cm");
    legend->AddEntry(graph_5, "Run 5, 180 mC/cm");
//    legend->AddEntry(graph_6, "Run 6, ? mC/cm");
    //legend->AddEntry(graph_7, "Run 7, ? mC/cm");
    //legend->AddEntry(graph_8, "Run 8, ? mC/cm");
    //legend->AddEntry(graph_9, "Run 9, ? mC/cm");
    //legend->AddEntry(graph_10, "Run 10, ? mC/cm");
    
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    mg->Add(graph_0);
    mg->Add(graph_1);
    mg->Add(graph_2);
    mg->Add(graph_3);
    mg->Add(graph_4);
    mg->Add(graph_5);
    //mg->Add(graph_6);
    //mg->Add(graph_7);
    //mg->Add(graph_8);
    //mg->Add(graph_9);
    //mg->Add(graph_10);
    
    mg->SetTitle(title);
    
    mg->Draw("ALP");
    
    // Draw and label
    mg->GetXaxis()->SetTitle("Voltage (kV)");
	mg->GetYaxis()->SetTitle("Current (pA)");
    mg->GetXaxis()->SetRangeUser(2,4);
    
	legend->Draw("SAME");


    //Save the plots
    system("mkdir -p "+which_chamber+"/"+"Plots/");
	TString saveWhere = which_chamber+"/"+"Plots/darkcurrent_"+filename+".pdf";
	canvas->Update();
//    canvas->SaveAs(saveWhere.c_str());
    canvas->SaveAs(saveWhere);
	canvas;

	return 0;
}
