#include "snippet.C"
#include "root_tools.h"
#include "plotting_functions.h"
#include <vector>

int graph_section(TString which_chamber, string filename, string norm_or_no, PlotterLines hole_num, vector<PlotterLines> run);

void plot_cluster_charge(TString which_chamber, string which_plot, string norm_or_no) {
    ExcelSheet test(which_chamber+"/"+"analysis_page_cluster.csv");

    // This is the important bit! The first value refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. Doesn't have to be exact,
    // we have a function that makes things perfect. The 3rd number is the column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines hole_num(test, 2, 14, 0, 1);
    PlotterLines run_0(test, 2, 14, 1, 1);
    PlotterLines run_1(test, 2, 14, 2, 1);
    PlotterLines run_2(test, 2, 14, 3, 1);
    PlotterLines run_3(test, 2, 14, 4, 1);
    PlotterLines run_4(test, 2, 14, 5, 1);
    PlotterLines run_5(test, 2, 14, 6, 1);
    PlotterLines run_6(test, 2, 14, 7, 1);
    PlotterLines run_7(test, 2, 14, 8, 1);
    PlotterLines run_8(test, 2, 14, 9, 1);
    PlotterLines run_9(test, 2, 14, 10, 1);
    PlotterLines run_10(test, 2, 14, 11, 1);
    
    vector<PlotterLines> run;
    run.push_back(run_0); run.push_back(run_1); run.push_back(run_2); run.push_back(run_3); run.push_back(run_4); run.push_back(run_5); run.push_back(run_6); run.push_back(run_7); run.push_back(run_8); run.push_back(run_9); run.push_back(run_10);
    
    
    graph_section(which_chamber, which_plot,norm_or_no, hole_num, run);
}


int graph_section(TString which_chamber, string filename, string norm_or_no, PlotterLines hole_num, vector<PlotterLines> run){
	
    TString title;
    TString label;
    label = " ";
    if (norm_or_no=="ref"){
        label = ", Normalized to Ref. Layer (3,1)";
    }
    else if (norm_or_no=="irr"){
        label = ", Normalized to Irr. Layer (3,1)";
    }
    title = "Cluster Charge: Gaussian Mean"+label;
    
    
    
    // For this plot, the "i" in graphLine.line[thing].at(i) refers to which hole is being sourced. Guidlines here:
    // None: i=0
    // Irr 1,1: i=1
    // Irr 1,2: i=2
    // Irr 2,1: i=3
    // Irr 2,2: i=4
    // Irr 3,1: i=5
    // Irr 3,2: i=6
    // Ref 1,1: i=7
    // Ref 1,2: i=8
    // Red 2,1: i=9
    // Ref 2,2: i=10
    // Ref 3,1: i=11
    // Ref 3,2: i=12
    
    
    Color_t colors[] = {kBlue-10, kBlue-7, kBlue, kBlue+2, kAzure+4, kAzure+1, kRed, kRed+3, kRed-6, kOrange-3, kRed-3, kOrange+4};
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(23);

    TCanvas *canvas = make_canvas();
    TLegend *legend = make_legend();
    canvas->cd();

    // This function takes the line, and then loops through and returns graphs.
    TGraph* graph_irr_2_1 = make_graph_cluster(norm_or_no,3,run);
    TGraph* graph_irr_2_2 = make_graph_cluster(norm_or_no,4,run);
    TGraph* graph_irr_3_1 = make_graph_cluster(norm_or_no,5,run);
    TGraph* graph_irr_3_2 = make_graph_cluster(norm_or_no,6,run);
    TGraph* graph_ref_2_2 = make_graph_cluster(norm_or_no,10,run);
    TGraph* graph_ref_3_1 = make_graph_cluster(norm_or_no,11,run);
    
    TGraph* fin_graph_irr_2_1 = format_me_cluster(graph_irr_2_1, colors[6]);
    TGraph* fin_graph_irr_2_2 = format_me_cluster(graph_irr_2_2, colors[7]);
    TGraph* fin_graph_irr_3_1 = format_me_cluster(graph_irr_3_1, colors[8]);
    TGraph* fin_graph_irr_3_2 = format_me_cluster(graph_irr_3_2, colors[9]);
    TGraph* fin_graph_ref_2_2 = format_me_cluster(graph_ref_2_2, colors[0]);
    TGraph* fin_graph_ref_3_1 = format_me_cluster(graph_ref_3_1, colors[1]);
    
    
    //  legend, label by hand
    if (norm_or_no=="irr") {
        legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
        legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2) (irr)");
//        legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
        legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
    }
    else if (norm_or_no=="ref") {
        legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
        legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2) (irr)");
        legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
        legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
        legend->AddEntry(fin_graph_ref_2_2, "Ref (2,2)");
//        legend->AddEntry(fin_graph_ref_3_1, "Ref (3,1)");
    }
    else {
        legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
        legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2) (irr)");
        legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
        legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
        legend->AddEntry(fin_graph_ref_2_2, "Ref (2,2)");
        legend->AddEntry(fin_graph_ref_3_1, "Ref (3,1)");
    }
    
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    if (norm_or_no=="irr") {
        mg->Add(fin_graph_irr_2_1);
        mg->Add(fin_graph_irr_2_2);
//        mg->Add(fin_graph_irr_3_1);
        mg->Add(fin_graph_irr_3_2);
    }
    else if (norm_or_no=="ref") {
        mg->Add(fin_graph_irr_2_1);
        mg->Add(fin_graph_irr_2_2);
        mg->Add(fin_graph_irr_3_1);
        mg->Add(fin_graph_irr_3_2);
        mg->Add(fin_graph_ref_2_2);
//        mg->Add(fin_graph_ref_3_1);
    }
    else {
        mg->Add(fin_graph_irr_2_1);
        mg->Add(fin_graph_irr_2_2);
        mg->Add(fin_graph_irr_3_1);
        mg->Add(fin_graph_irr_3_2);
        mg->Add(fin_graph_ref_2_2);
        mg->Add(fin_graph_ref_3_1);
    }
    
    // title!
    mg->SetTitle(title);
    
    mg->Draw("ALP");

    
    //  label
    mg->GetXaxis()->SetTitle("Accumulated charge (mC/cm)");
    if ( (norm_or_no=="ref") || (norm_or_no=="irr") ) {
        mg->GetYaxis()->SetTitle("Ratio");
    }
    else{
        mg->GetYaxis()->SetTitle("ADC Counts");
    }
    if (norm_or_no=="ref" or norm_or_no=="irr"){
        mg->GetYaxis()->SetRangeUser(0.86, 1.3);
    }
    else{
        mg->GetYaxis()->SetRangeUser(900, 1600);
    }

	legend->Draw("SAME");

    // Save plots
    system("mkdir -p "+which_chamber+"/"+"Plots/");
	TString saveWhere = which_chamber+"/"+"Plots/cluster_"+filename+norm_or_no+".pdf";
	canvas->Update();
//    canvas->SaveAs(saveWhere.c_str());
    canvas->SaveAs(saveWhere);
	canvas;

	return 0;
}
