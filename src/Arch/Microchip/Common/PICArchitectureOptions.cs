﻿#region License
/* 
 * Copyright (C) 2017-2018 Christian Hostelet.
 * inspired by work from:
 * Copyright (C) 1999-2018 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using System;
using Reko.Libraries.Microchip;

namespace Reko.Arch.MicrochipPIC.Common
{

    /// <summary>
    /// A PIC architecture options specifying PIC target model and potential instruction set execution mode.
    /// </summary>
    public class PICArchitectureOptions
    {

        public PICArchitectureOptions() { }

        public PICArchitectureOptions(IPICProcessorMode processorMode, PICExecMode execMode)
        {
            ProcessorMode = processorMode ?? throw new ArgumentNullException(nameof(processorMode));
            PICExecutionMode = execMode;
        }

        public PICArchitectureOptions(string picName, PICExecMode execMode) : this(PICProcessorMode.GetMode(picName), execMode)
        {
        }

        public PICArchitectureOptions(PICArchitectureOptionsPicker picker)
        {
            if (picker == null)
                throw new ArgumentNullException(nameof(picker));
            ProcessorMode = PICProcessorMode.GetMode(picker.PICName);
            PICExecutionMode = (picker.AllowExtended ? PICExecMode.Extended : PICExecMode.Traditional);
        }

        /// <summary>
        /// Gets or sets the processor mode builders.
        /// </summary>
        public IPICProcessorMode ProcessorMode { get; set; }

        /// <summary>
        /// Gets or sets the PIC instruction set execution mode.
        /// </summary>
        public PICExecMode PICExecutionMode { get; set; }

    }

    /// <summary>
    /// Class used to get the architecture optios from the user..
    /// </summary>
    public class PICArchitectureOptionsPicker
    {
        public PICArchitectureOptionsPicker()
        { }

        public PICArchitectureOptionsPicker(PICArchitectureOptions opts)
        {
            if (opts == null)
                throw new ArgumentNullException(nameof(opts));
            PICName = opts.ProcessorMode.PICName;
            AllowExtended = opts.PICExecutionMode == PICExecMode.Extended;
        }

        /// <summary>
        /// Name of the PIC.
        /// </summary>
        public string PICName { get; set; }

        /// <summary>
        /// True to permit decoding of Extended Execution mode of PIC18, false otherwise.
        /// This is a hint in case the configuration fuses are not part of the binary image.
        /// </summary>
        public bool AllowExtended { get; set; }

        public override string ToString() => $"{PICName}{(AllowExtended ? ",Extended" : "")}";

    }

}
