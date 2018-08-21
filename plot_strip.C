#include "snippet.C"
#include "root_tools.h"
#include "plotting_functions.h"

int graph_section(TString which_chamber, vector<PlotterLines> run);


void plot_strip(TString which_chamber) {
    ExcelSheet test(which_chamber+"/"+"analysis_page_strip.csv");

    // This is the important bit! The first value refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. Doesn't have to be exact,
    // we have a function that makes things perfect. The 3rd number is the column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines run_0(test, 2, 5, 0, 2);
    PlotterLines run_1(test, 2, 5, 3, 2);
    PlotterLines run_2(test, 2, 5, 6, 2);
    PlotterLines run_3(test, 2, 5, 9, 2);
    PlotterLines run_4(test, 2, 5, 12, 2);
    PlotterLines run_5(test, 2, 5, 15, 2);
    PlotterLines run_6(test, 2, 5, 18, 2);
    PlotterLines run_7(test, 2, 5, 21, 2);
    PlotterLines run_8(test, 2, 5, 24, 2);
    PlotterLines run_9(test, 2, 5, 27, 2);
    PlotterLines run_10(test, 2, 5, 30, 2);
    
    vector<PlotterLines> run;
    run.push_back(run_0); run.push_back(run_1); run.push_back(run_2); run.push_back(run_3); run.push_back(run_4); run.push_back(run_5); run.push_back(run_6); run.push_back(run_7); run.push_back(run_8); run.push_back(run_9); run.push_back(run_10);
    
    graph_section(which_chamber, run);
}


int graph_section(TString which_chamber, vector<PlotterLines> run){
	
    // For this plot, the "i" in graphLine.line[thing].at(i) refers to the wire pair being used,
    // following the formula i+1 i.e. at(0) is pair 1, etc
    
    
    Color_t colors[] = {kBlue-10, kBlue-7, kBlue, kBlue+2, kAzure+4, kAzure+1, kRed, kRed+3, kRed-6, kOrange-3, kRed-3, kOrange+4, kPink, kGreen};
    
    int acc_charge[] = {0, 53, 95, 121, 149, 180};
    int number_of_points = 6;
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
//    gStyle->SetTitleAlign(13);

    TCanvas *canvas = make_canvas();
    TLegend *legend = make_legend();
	canvas->cd();

    
    // This function takes the line (which has been correctly sized), and then loops through and returns graphs for the corresponding wire pair
    TGraph* graph_pair_1 = make_graph_strip(0,run, acc_charge, number_of_points);
    TGraph* graph_pair_2 = make_graph_strip(1,run, acc_charge, number_of_points);
    TGraph* graph_pair_3 = make_graph_strip(2,run, acc_charge, number_of_points);
    TGraph* graph_pair_4 = make_graph_strip(3,run, acc_charge, number_of_points);
    
    
    //Run the plots through the formater, select the desired colors from the list at beginning of function
    TGraph* fin_graph_pair_1 = format_me_strip(graph_pair_1, colors[7]);
    TGraph* fin_graph_pair_2 = format_me_strip(graph_pair_2, colors[6]);
    TGraph* fin_graph_pair_3 = format_me_strip(graph_pair_3, colors[1]);
    TGraph* fin_graph_pair_4 = format_me_strip(graph_pair_4, colors[2]);
    
    // Label the legend by hand
    legend->AddEntry(fin_graph_pair_1, "Wire pair 1 (irr layer) (irr)");
    legend->AddEntry(fin_graph_pair_2, "Wire pair 2 (irr layer)");
    legend->AddEntry(fin_graph_pair_3, "Wire pair 3 (ref)");
    legend->AddEntry(fin_graph_pair_4, "Wire pair 4 (ref)");

    
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    mg->Add(fin_graph_pair_1);
    mg->Add(fin_graph_pair_2);
    mg->Add(fin_graph_pair_3);
    mg->Add(fin_graph_pair_4);
    
    canvas->SetLogy();
    
    // title
    mg->SetTitle("Strip-to-Strip Resistance");
    
    mg->Draw("ALP");

    
    //  label axis
    mg->GetXaxis()->SetTitle("Accumulated charge (mC/cm)");
    mg->GetYaxis()->SetTitle("Resistance (TOhms)");
    // Set the y range so that the legend doesn't cover up any points
    mg->GetYaxis()->SetRangeUser(0.05, 220);
	legend->Draw("SAME");

    
    
    // Locate where it goes and gets saved
    system("mkdir -p "+which_chamber+"/"+"Plots/");
    TString saveWhere = which_chamber+"/"+"Plots/strip_to_strip.pdf";
    canvas->Update();
//    canvas->SaveAs(saveWhere.c_str());
    canvas->SaveAs(saveWhere);
    canvas;

	return 0;
}
