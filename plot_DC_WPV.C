#include "snippet.C"
#include "plotting_functions.h"
#include <vector>
#include "root_tools.h"

int graph_section(TString which_chamber, vector<PlotterLines> irr, vector<PlotterLines> ref);

void plot_DC_WPV(TString which_chamber) {
    ExcelSheet test(which_chamber+"/"+"analysis_page_darkCurrent.csv");
    
    // This is the important bit! The first value refers to the excel sheet above. The second number is
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
    
    
    graph_section(which_chamber, irr, ref);
}


int graph_section(TString which_chamber, vector<PlotterLines> irr, vector<PlotterLines> ref){
    
    // For this plot, the "i" in graphLine.line[thing].at(i) refers to the wire pair being used,
    // following the formula i+1 i.e. at(0) is pair 1, etc

    
    int acc_charge[] = {0, 53, 95, 121, 149, 180};
    int num_or_points = 6;
    
    //Just some styling stuff
    gROOT->SetBatch(true);
    gStyle->SetOptStat(2210);
    //    gStyle->SetTitleAlign(13);
    
    TCanvas *canvas = make_canvas();
    canvas->cd();
    TLegend *legend = make_legend();
    
    
    // This function takes the line (which has been correctly sized), and then loops through and returns graphs for the corresponding wire pair
    //first argument is the row number, which corresponds to the row within the Plotterlines block where the 3.6 kV value is
    TGraph* graph_DC_irr = make_graph_DC(4,irr, acc_charge, num_or_points);
    TGraph* graph_DC_ref = make_graph_DC(2,ref, acc_charge, num_or_points);
    
    
    //Run the plots through the formater, select the desired colors from the list at beginning of function
    TGraph* fin_graph_DC_irr = format_me_DC(graph_DC_irr, kRed+2, 1);
    TGraph* fin_graph_DC_ref = format_me_DC(graph_DC_ref, kBlue+3, 1);
    
    
    // Label the legend by hand
    legend->AddEntry(fin_graph_DC_irr, "Irradiated Layer");
    legend->AddEntry(fin_graph_DC_ref, "Reference Layer");
    
    
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    mg->Add(fin_graph_DC_irr);
    mg->Add(fin_graph_DC_ref);
    
    //    canvas->SetLogy();
    
    // title
    mg->SetTitle("Dark Current at 3.6 kV");
    
    mg->Draw("ALP");
    
    
    //  label axis
    mg->GetXaxis()->SetTitle("Accumulated charge (mC/cm)");
    mg->GetYaxis()->SetTitle("Current [pA]");
    mg->GetYaxis()->SetRangeUser(0., 1200);
    legend->Draw("SAME");
    
    // Locate where it goes and gets saved
    system("mkdir -p "+which_chamber+"/"+"Plots/");
    TString saveWhere = which_chamber+"/"+"Plots/darkcurrent_WPV.pdf";
    canvas->Update();
    canvas->SaveAs(saveWhere);
    delete canvas;
    
    return 0;
}

